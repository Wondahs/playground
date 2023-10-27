" Set mouse and laststatus
set mouse=a
set laststatus=2

" Use Ctrl+Enter to select suggestions in insert mode
inoremap <C-Enter> <C-x><C-o>

" Use Enter to select suggestions or add a new line in insert mode
inoremap <expr> <CR> pumvisible() ? "\<C-y>" : "\<CR>"

" Set the runtime path for Vundle and initialize Vundle
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

" Add coc.nvim to the list of plugins
Plugin 'neoclide/coc.nvim', {'branch': 'release'}
let g:coc_global_extensions = ['coc-clangd', 'coc-python', 'coc-json']

" Other Vim configurations go here...

" End Vundle
call vundle#end()

" Initialize plug.vim for managing plugins
call plug#begin('~/.vim/plugged')

" Your plugins go here...
Plug 'vim-scripts/vimtap'
Plug 'preservim/nerdtree', { 'on': 'NERDTreeToggle' }
Plug 'tpope/vim-fireplace', { 'for': 'clojure' }
Plug 'rdnetto/YCM-Generator', { 'branch': 'stable' }
Plug 'csexton/trailertrash.vim'

" Map keys for various functions
nnoremap <F2> :!betty %<CR>
nnoremap <F4> :TrailerTrim<CR>
nnoremap <F3> :%norm! ggVG=<CR>
nnoremap <F5> :Compile<CR>

" Compile via vim
function! Compile()
  let source_filename = expand('%')
  let number = matchstr(source_filename, '\d\+')
  let test_filename = number . '-main.c'
  let output_filename = substitute(source_filename, '\.c$', '', '')
  let command = 'gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c ' . source_filename . ' ' . test_filename . ' -o ' . output_filename
  execute '!'.command
endfunction

command! -nargs=0 Compile :call Compile()

"set number
"set relativenumber
set autoindent
filetype indent on
syntax on
set wildmenu
set wildmode=list:longest
set wildignore=*.docx,*.jpg,*.png,*.gif,*.pdf,*.pyc,*.exe,*.flv,*.img,*.xlsx

" Use vim-syntastic for Python linting
Plug 'vim-syntastic/syntastic'
syntax enable
set statusline+=%#warningmsg#
set statusline+=%{SyntasticStatuslineFlag()}
set statusline+=%*

" Map a shortcut key to run the linter
nmap <C-c> :SyntasticCheck<CR>

" End plug.vim
call plug#end()

