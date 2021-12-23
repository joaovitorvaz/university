import styled from 'styled-components';

// Containers
export const Main = styled.main`
  width: 100%;
  display: flex;  
  flex-direction: column;
`;

export const ContainerImage = styled.div`
  width: 100%;
  padding-top: 100px;
  display: flex;
  flex-direction: column;
  background-repeat: no-repeat, repeat;
`;

export const ContainerBox = styled.div`
  padding-top: 100px;
`

// Animations
export const Box = styled.main`
  display: flex;
  height: 100vh;
  width: 100%;
  background-color: #141414;
  justify-content: center;
  align-items: center;
`;

export const Loader = styled.div`
  animation: is-rotating 1s infinite;
  border: 6px solid ${({ theme }) => theme.colors.secondary};
  border-radius: 50%;
  border-top-color: ${({ theme }) => theme.colors.light};
  height: 45px;
  width: 45px;

  @keyframes is-rotating {
    to {
      transform: rotate(1turn);
    }
  }
`;
