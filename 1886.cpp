class Solution {
    public boolean findRotation(int[][] mat, int[][] target) {
        if(Arrays.deepEquals(mat, target))return true;
        for(int rotations = 1; rotations < 4; rotations++){
            rotate(mat);
            if(Arrays.deepEquals(mat, target))return true;
        }
        return false;
    }

    private void rotate(int[][] mat){
        int[][] rotated = new int[mat.length][mat[0].length];
        for(int r = 0; r < mat.length; r++){
            for(int c = 0; c < mat[0].length; c++){
                rotated[c][mat.length-1-r] = mat[r][c];
            }
        }

        for(int r = 0; r < mat.length; r++){
            for(int c = 0; c < mat[0].length; c++){
                mat[r][c] = rotated[r][c];
            }
        }
    }
}
