//caidi.c
//by mask 99/11


#include <ansi.h>
inherit ROOM;

void create()
{

         set("short", "�˵�");
         set("long", @LONG                              
�������䵱ɽ�Ĳ˵أ����ﳤ���������͵��߲ˣ����˿��ž;���
����������������ڵ���ժ��(zhaicai)��
LONG
         );
         set("no_fight",1);
         set("exits", ([
                 "east" :__DIR__"guangchang",
         ]));

         setup();
         //replace_program(ROOM);
}
void init()
{
add_action("do_sa","zhaicai");
}
int do_sa(string arg)
{
         
         object me,ob,fish;
         int n;
         n = 0;         me=this_player();

         if (!me->query_temp("job")||me->query_temp("job")!=1)
         {
         tell_object(me,"��Ҫ���\n");
         return 1;
         }
         if(me->is_busy())
         return notify_fail("����æ���ء�\n");

         if(me->query_temp("cai",1))
         {
         write(HIR"��Ѳ��͵��𹤵�������ȥ�ɡ�\n",NOR);
         return 1;
         }
else
{       
  if(me->query("jing")<10)
  return notify_fail("�����̫���ˣ�Ӧ����Ϣһ���ˡ�\n");
         message_vision(HIG"$N������ʼ��ѡ���۵��߲ˡ�\n"NOR,me); 
         n++; 
         me->receive_damage("jing",10);
        
 if (random(5)>=3||n >= 8)
{    
         message_vision(HIC"$Nժ����һ���ʲˣ�����𹤵�����ȥ�ɣ�\n"NOR,me);
         fish=new("/d/wudang/obj/cai");
         fish->move(me); 
         n=0;
         me->set_temp("cai",1);
         return 1;
}
else
{
         me->start_busy(5);
         return 1;
}
return 1;
}
return 1;
}

