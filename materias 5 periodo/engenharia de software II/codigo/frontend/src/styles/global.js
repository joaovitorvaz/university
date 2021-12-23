import { createGlobalStyle } from 'styled-components';

export default createGlobalStyle`
  html{
    scroll-behavior: smooth;
    -webkit-tap-highlight-color: transparent;
  }

  ::-webkit-scrollbar-track{
    background: #10002B;
  }

  ::-webkit-scrollbar {
    width: 10px;
    background: #200041;
  }

  ::-webkit-scrollbar-thumb{
    background: #6B33FF;
  }

  ::-webkit-scrollbar-thumb:hover{
    background: #C41EA2;
  }

  ::-webkit-input-placeholder {
    color: #200041;
    font-weight: bold;
    padding-left: 5px;
  }

  * {
    box-sizing: border-box;
    color: #DFDFDF;
    font-family: 'Anton', sans-serif;
  }

  html, body {
    margin: 0;
    padding: 0;
    box-sizing: border-box;
    background-color: #10002B;
    font-family: 'Anton', sans-serif;
  }

  a {
    color: inherit;
    text-decoration: none;
  }
`;
