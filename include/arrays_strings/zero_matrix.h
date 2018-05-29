#pragma once
#include <vector>

namespace algorithm{
    using matrix=std::vector<std::vector<int>>;

    void zero_matrix_inplace(matrix& mat){
        if(!mat.size()) return;
        for(std::size_t i=0;i<mat.size();++i){
            for(std::size_t j=0; j<mat[0].size();++j){
                if(mat[i][j]==0){
                    mat[i][0]=0;
                    mat[0][j]=0;
                }
            }
        }
        for(std::size_t i=0;i<mat.size();++i){
            for(std::size_t j=0; j<mat[0].size();++j){
                if(mat[i][0]==0 || mat[0][j]==0){
                    mat[i][j]=0;
                }
            }
        }
    }
}