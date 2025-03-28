syntax on
set number
set mouse=a
let g:netrw_banner = 0
let NERDTreeShowHidden=1
"set relativenumber
"let g:netrw_liststyle = 3
"let g:netrw_liststyle = 1
"let g:netrw_browse_split = 3

call plug#begin("")

Plug 'ryanoasis/vim-devicons'
Plug 'https://github.com/preservim/nerdtree'
Plug 'https://github.com/ap/vim-css-color'
Plug 'https://github.com/vim-airline/vim-airline'
Plug 'https://github.com/rafi/awesome-vim-colorschemes'
Plug 'https://github.com/preservim/tagbar'

call plug#end()

let g:airline_theme='afterglow'
colorscheme afterglow

nnoremap <C-n> :NERDTreeToggle<CR>
nnoremap <C-t> :TagbarToggle<CR>
