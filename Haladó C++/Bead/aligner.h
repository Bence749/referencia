#ifndef aligner__h
#define aligner__h

#include <iostream>
#include <string>
#include <vector>

template<typename T>
class aligner
{
    public:
        std::vector<std::vector<T>*> toAlign;
        T defaultValue = T();

        void add( std::vector<T>& vec  ){ toAlign.push_back( &vec ); }
        virtual void align(){};
        int count(){ return toAlign.size(); }
        void set_filler( T filler ){ defaultValue = filler; }
        void print()
        {
            for(auto x : toAlign )
            {
                for(auto y : x)
                    std::cout << y << ' ';
                std::cout << std::endl;
            }
        }

        virtual ~aligner() { };
};

template<typename T>
class left_aligner : public aligner<T>
{
    virtual void align()
    {
        int maxLength = 0;
        for( const std::vector<T>* vector : this->toAlign )
            if( int(vector->size()) > maxLength ) maxLength = vector->size();

        for( std::vector<T>* vector : this->toAlign )
            if( int(vector->size()) != maxLength) vector->resize( maxLength, this->defaultValue );
    };
};

template<typename T>
class right_aligner : public aligner<T>
{
    virtual void align()
    {
        int maxLength = 0;
        for( const std::vector<T>* vector : this->toAlign )
            if( int(vector->size()) > maxLength ) maxLength = vector->size();

        for( std::vector<T>* vector : this->toAlign )
            if( int(vector->size()) != maxLength) vector->insert( vector->begin(), 
                                                           maxLength - vector->size(), this->defaultValue );
    };
};

template<typename T>
class center_aligner : public aligner<T>
{
    virtual void align()
        {
            int maxLength = 0;
            for( const std::vector<T>* vector : this->toAlign )
                if( int(vector->size()) > maxLength ) maxLength = vector->size();

            for( std::vector<T>* vector : this->toAlign )
                if( int(vector->size()) != maxLength) 
                {
                    vector->insert( vector->begin(), (maxLength - vector->size()) / 2, this->defaultValue );
                    vector->resize(maxLength);
                }
        };
};

#endif