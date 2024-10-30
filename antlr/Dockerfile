FROM eclipse-temurin:17

WORKDIR /usr/local/lib
RUN wget https://www.antlr.org/download/antlr-4.13.2-complete.jar
ENV CLASSPATH=".:/usr/local/lib/antlr-4.13.2-complete.jar:$CLASSPATH"

ENTRYPOINT ["java", "-jar", "/usr/local/lib/antlr-4.13.2-complete.jar"]
CMD []
