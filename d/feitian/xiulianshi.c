//shushan2 by yushu@SHXY 2001.2
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "[1;31m������[2;37;0m");
  set ("long", @LONG
��������Ż����������ң�������ϰ��������߽������ã�ǽ������˼�
����,�����ȡһ��(lianxi)��ϰ���������Ǽ���Ϣ��������������Ϣ֮�á�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"qianting",
  "east" : __DIR__"xiuxishi",
]));
  set("outdoors", 2);

  setup();
//  replace_program(ROOM);
}

void init()
{
        add_action("do_lianxi", "lianxi");
}

int do_lianxi()
{
    object me=this_player();
          if(me->is_busy() )
          return notify_fail("������æ���أ������ϰ...\n");

        if((int)me->query_skill("parry",1)<120 )
               return notify_fail("���м�̫�ͣ��޷���ϰ��\n");
   
        if(me->query("family/family_name") != "����������")
        {
        tell_object(me,"�㲻�Ƿ����������ģ���������͸�ʲô��\n"); 
        return 1;
        }
        if(me->query("qi") < 100)
        {
        tell_object(me,"�㻹������Ϣһ����ɡ�\n");     
        return 1;
        }
        message_vision("$N����ʦ����ָ˫������,�������»��裬��ϰ��������ս�������\n", me);
        me->add("qi",-10);
        me->start_busy(1);
        if(me->query("feitian/chaodao")) 
        {
        tell_object(me,"���ƺ�������������ϰ��ʲô�ˡ�\n");       
        return 1;
        }
        if((int)me->query_skill("huoxinliu-jianfa", 1) > 120){
        tell_object(me,HIW"�㷴����ϰ������Լ��[����]����Щ��ᣡ\n"NOR);
        me->add("feitian/lianxi",1);
        me->start_busy(1);
        }
        if(me->query("feitian/lianxi",1) > 200)
        {
        me->set("feitian/chaodao",1);
        tell_object(me,HIG"�㷴����ϰ������ᵽ�ٶȸ���������Ҫ�ˣ����ÿ���ʹ��[����]��\n"NOR);
        me->delete("feitian/lianxi");
        }
        return 1;
}             
