// danfang.c ����
// Modify By River 99.5.25
inherit ROOM;

#include <ansi.h>
void create()
{
           set("short",HIG"����"NOR);
           set("long",@LONG
��������У�ֻ�����ϣ���������ҩƿ������һ�ԴԵĹ�������Ǭ��ҩ��
���ײ���������¯(lu)�����ʯ���Ա�����ν�����ˡ�
LONG
           );
			
	   set("exits",([
               "south": __DIR__"lang2",
           ]));
	   set("item_desc",([
              "lu": "���ǹ�����������ĵ�¯����������Ϊ��ͨ�������ƺ�����Щ����ȥ���Ծ���\n",
           ]));
            
	   setup();
}

void init()
{
         add_action("do_tui","tui");
}

int do_tui(string arg)
{   
          object me = this_player();
          if( !arg || arg==" " ) return notify_fail ("��Ҫ��ʲô����\n");
          if (arg =="lu")
               return notify_fail("��Ҫ���ıߵĵ�¯����\n");
          if (me->query_skill("force", 1) < 120 ) 
               return notify_fail("����������˿������������Ƶ�¯������������������¯˿��������\n");
          if (me->query_str() < 30 ) 
               return notify_fail("����������˿������������Ƶ�¯������������������¯˿��������\n");
          if( arg=="zhonglu" || arg=="middlelu"){
           if (me->query_temp("jqg/tui"))
                 return notify_fail("���Ѿ��ѵ�¯�ƺ��ˡ���������ʲô��\n");  
               me->set_temp("jqg/tui", 1);
               tell_object(me,"���Ƚ��м�ĵ�¯�ƿ���\n");
               message("vision",me->name() +"�м�ĵ�¯�ƿ���\n"NOR,environment(me), me);
               return 1;
               }
          if (!me->query_temp("jqg/tui")) return 0;
          if( arg == "donglu" || arg == "eastlu" 
           || arg == "westlu" || arg == "xilu" )
               return notify_fail("��Ҫ�ѵ�¯�������ﰡ��\n");
          if( arg =="donglu middle" || arg =="eastlu middle" 
           || arg =="donglu zhong" || arg =="eastlu zhong"){
           if (me->query_temp("jqg/tuidong"))
                 return notify_fail("���Ѿ��ѵ�¯�ƺ��ˡ���������ʲô��\n");  
               tell_object(me,"���ٽ����׵�һ����¯�Ƶ��м䡣\n");
               message("vision",me->name() +"���׵�һ����¯�Ƶ��м䡣\n"NOR,environment(me), me);
               me->start_busy(1);
               me->set_temp("jqg/tuidong", 1);
               return 1;
	       }
 	  if( arg =="xilu east" || arg =="westlu east" 
           || arg =="xilu dong" || arg =="westlu dong"){
           if (! me->query_temp("jqg/tuidong")) return 0;
           if ( me->query_temp("jqg/tuixi"))
                 return notify_fail("���Ѿ��ѵ�¯�ƺ��ˡ���������ʲô��\n");
               tell_object(me,"�����㽫���׵�һ����¯�Ƶ����ס�\n");
               message("vision",me->name() +"�����׵�һ����¯�Ƶ����ס�\n"NOR,environment(me), me);
               me->start_busy(1);
               me->set_temp("jqg/tuixi", 1);
               return 1;
               }
          if(arg =="zhonglu west" || arg =="middlelu west" 
            || arg =="zhonglu xi" || arg ==" middlelu xi"){
           if (! me->query_temp("jqg/tuixi")) return 0;
               tell_object(me,"Ȼ���㽫�м��һ����¯�Ƶ����ס�\n");
               message("vision",me->name() +"���м��һ����¯�Ƶ����ס�\n"NOR,environment(me), me);
               me->start_busy(1);
               tell_object(me,HIR"\n�������һ��ȴ��̤�˸��ա���ʱ��ֱ���£�������׿��飬����ֱ������ʮ����δ���ء�\n\n"NOR);
               message("vision",me->name() +"������һ����ʱ��ֱ���¡�\n"NOR,environment(me), me);
               me->delete_temp("jqg");
               me->move(__DIR__"eytan");
               tell_object(me,HIR"\n����ǰһƬ�ڰ�����ͨһ������ˤ��ˮ�У����¼�����ԭ������֮�¾��Ǹ���Ԩ��\n\n"NOR);
               message("vision", me->name() +"��ǰһƬ�ڰ�����ͨһ������ˤ��ˮ�С�\n",environment(me), me);
             if( me->query_skill("dodge", 1) < 120){
                 me->receive_damage("qi", 200);
                 me->receive_wound("qi", 200);
                 me->unconcious();
                 return 1;
                 }
               return 1; 
               }               
}
