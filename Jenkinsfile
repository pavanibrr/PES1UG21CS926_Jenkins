pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                script {
                    // Compile the .cpp file using a shell script
                    build 'PES1UG21CS926-1'
                    sh 'g++ -o my_program task5.cpp'
                }
            }
        }

        stage('Test') {
            steps {
                script {
                    // Print output of .cpp file using a shell script
                    sh './my_program'
                }
            }
        }

        stage('Deploy') {
            steps {
                // Add deployment steps here if needed
                echo 'Deploy'
            }
        }
    }

    post {
        always {
            // Display 'pipeline failed' in case of any errors within the pipeline
            script {
                if (currentBuild.result == 'FAILURE') {
                    echo 'Pipeline failed'
                }
            }
        }
    }
}
