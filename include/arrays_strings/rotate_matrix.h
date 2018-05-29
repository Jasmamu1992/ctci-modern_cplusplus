#pragma once

#include <vector>

namespace algorithm{
    using image_type=std::vector<std::vector<__UINT32_TYPE__>>;
    /*
    *Implementation 
    *complexity Time:O(N), Memory:O(1) Inplace
    *N:number of elements in the image matrix 
    */
    void rotate_matrix_best(image_type& mat){
        if(!(mat.size())) return;
        if(mat.size()!=mat[0].size()) std::__throw_invalid_argument("Not a square matrix");
        std::size_t start = 0;
        std::size_t end = mat.size()-1;
        while(start<end){
            for(std::size_t index=0; index<(end-start); ++index){
                auto top_right = mat[start+index][end];
                mat[start+index][end] = mat[start][start+index];
                auto bottom_right = mat[end][end-index];
                mat[end][end-index] = top_right;
                auto bottom_left = mat[end-index][start];
                mat[end-index][start] = bottom_right;
                mat[start][start+index] = bottom_left;
            }
            start++;
            end--;
        } 
    }

    void transpose(image_type& mat){
        for(std::size_t i=0; i<mat.size();++i){
            for(std::size_t j=i; j<mat[0].size();++j){
                std::swap(mat[i][j], mat[j][i]);
            }
        }
    }

    void reversecolumns(image_type& mat){
        for(std::size_t i=0; i<mat.size();++i){
            for(std::size_t j=0; j<mat[0].size()/2;++j){
                std::swap(mat[i][j], mat[i][mat[0].size()-j-1]);
            }
        }
    }
    /*
    *Implementation is not the best in terms of efficiency
    *But it is best in terms of simplicity
    *complexity Time:O(N), Memory:O(1) Inplace
    *N:number of elements in the image matrix 
    */
    void rotate_matrix(image_type& mat){
        if(!(mat.size())) return;
        if(mat.size()!=mat[0].size()) std::__throw_invalid_argument("Not a square matrix");
        transpose(mat);
        reversecolumns(mat);
    }
}