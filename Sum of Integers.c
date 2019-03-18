#include <stdio.h>
    main()
   {
      int i, sum = 0, a[100];
        for(i = 0; i < 100; i++){
        scanf("%d",&a[i]);
          do
            sum = sum + a[i];
          while(scanf("%d", &a[i]) == 1);
        printf("%d\n", sum);
        break;
      }

      return 0;
   }
