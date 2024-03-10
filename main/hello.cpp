pipeline { // The top-level 'pipeline' block is essential
    agent any

    stages {
        stage('Build') { 
            steps {
                script { 
                    // Compile .cpp file
                    sh 'g++ -o myExecutable main/hello.cpp' 
                }
            }
        }

        stage('Test') { 
            steps {
                script { 
                    // Run the executable
                    sh './myExecutable' 
                }
            }
        }

        stage('Deploy') { 
            steps {
                script { 
                    // Deployment steps 
                    echo "Deployment completed successfully" 
                }
            }
        }
    }

    post {
        success {
            echo "Pipeline succeeded" 
            // Additional success actions
        }

        failure {
            echo "Pipeline failed"
            // Additional failure actions
        }
    }
}
