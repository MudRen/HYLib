int valid_leave(object me, string dir)
{
        if (dir == "west")
         me->add_temp("mark/step",1);
        if (dir == "south")
          me->add_temp("mark/steps",1);
        if (dir == "east")
          me->add_temp("mark/step",-1); 
        if (dir == "north")
          me->add_temp("mark/steps",-1);
        if (random(10)==1
		 && random(2)==1 )
         {
            me->move(__DIR__"xdt");
            me->delete_temp("mark/steps");
            me->delete_temp("mark/step");
             return notify_fail("�������ţ�͸����֦����Լ����ǰ����Ƭ�յأ��㲦����֦���˹�ȥ��\n");
         }  
        if (me->query_temp("mark/steps") == -5&&me->query_temp("mark/step") == 6)
         {
            me->move(__DIR__"lsy");
            me->delete_temp("mark/steps");
            me->delete_temp("mark/step");
             return notify_fail("�������ţ�ͻȻ����ǰ����һ��Сľ��,�㲻�ɵ����˹�ȥ��\n");
         }  
     if (me->query_temp("mark/steps") > 10)
            {  
           me->move(__DIR__"road7");
           me->delete_temp("mark/steps");
           me->delete_temp("mark/step");
 return notify_fail("���ƣ����,�����߳������֡�\n");

        }
           
        return ::valid_leave(me, dir);
}

