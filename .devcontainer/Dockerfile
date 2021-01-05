
FROM gcc:latest

ARG USERNAME
ARG HOME
ARG DOCKER_VOLUME

ENV USERNAME ${USERNAME}
ENV HOME ${HOME}
ENV DOCKER_VOLUME ${DOCKER_VOLUME}

ENV USER_UID 1000
ENV USER_GID ${USER_UID}

ENV TZ=Europe/Warsaw

RUN export DEBIAN_FRONTEND=noninteractive \
  && export APT_KEY_DONT_WARN_ON_DANGEROUS_USAGE=DontWarn \
  && apt-get update \
  && apt-get -y install \
    apt-utils \
    build-essential \
    clang-format \
    cmake \
    cppcheck \
    curl \
    dos2unix \
    file \
    git \
    jq \
    lcov \
    openssl \
    sudo \
    telnet \
    valgrind \
    vim \
  && apt-get autoremove -y \
  && apt-get clean -y \
  && rm -rf /var/lib/apt/lists/*

RUN \
  groupadd --gid ${USER_GID} ${USERNAME} \
  && useradd --uid ${USER_UID} --gid ${USERNAME} --shell /bin/bash --create-home ${USERNAME} \
  && usermod --password $(echo ${USERNAME} | openssl passwd -1 -stdin) ${USERNAME} \
  \
  && usermod -aG sudo ${USERNAME} \
  && echo ${USERNAME} ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/${USERNAME} \
  && chmod 0440 /etc/sudoers.d/${USERNAME}

ENV DOCKER_VOLUME ${HOME}/volume
ENV PROMPT_COMMAND 'history -a'

RUN \
  mkdir -p \
    ${DOCKER_VOLUME} \
    ${DOCKER_VOLUME}/.vscode-server/extensions \
    ${DOCKER_VOLUME}/.vscode-server-insiders/extensions \
  && touch ${DOCKER_VOLUME}/.bash_history \
  && ln -s ${DOCKER_VOLUME}/.bash_history ${HOME}/.bash_history \
  && ln -s ${DOCKER_VOLUME}/.vscode-server ${HOME}/.vscode-server \
  && ln -s ${DOCKER_VOLUME}/.vscode-server-insiders ${HOME}/.vscode-server-insiders \
  && chown -R ${USERNAME}:${USERNAME} ${HOME}

WORKDIR ${HOME}
USER ${USERNAME}