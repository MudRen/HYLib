// caoyuan3.c ��ԭ
inherit ROOM;

#include <ansi.h>

void create()
{
        set("short", "��ԭ");
        set("long", @LONG
���߽���������಻���Ĵ��ԭ�������Ǵ�����ݣ�������Ļ�
�治���ߣ�������ƥ�����������ǵĺ����⡣���߿��Կ�����ԭ������
��ȥ����ɳĮ�ˡ�����������һЩ�Ŵ���ʯ�񣬲�֪����ǹ��һ�»���
ô����
LONG);
        set("exits", ([
            "southwest" : __DIR__"caoyuan3",
           
        ]));
set("objects",(["/clone/npc/man":1,]));	
        set("outdoors", "dingxiang");
        setup();
        
}

void init()
{
   add_action("do_ci","ci");
}

int do_ci(string arg)
{
   object me,weapon;
   me=this_player();
   if(!arg||arg!="ʯ��")
   return notify_fail("��Ҫ��ʲô��\n");
   if(!objectp(weapon=me->query_temp("weapon")))
   return notify_fail("û����������Ҫ���ִ���\n");
   if(weapon->query("skill_type")!="spear")
   return notify_fail("��Ӷ�"+weapon->name()+"���˼��£����ֺ����ô���\n");
   if(weapon->query("flag")==1)
   return notify_fail("���ɥ�ķ������еı����Ѿ��ϵ��ˣ�\n");
   if(me->query("sen")<20)
   return notify_fail("�㾫��̫���ˣ�\n");
   if(me->query_skill("spear",1)>=101)
   return notify_fail("һ���������˹��������������׼�Ҵ̣�\n");
   if(me->is_busy())
   return notify_fail("����æ���أ�\n");
   
   message_vision(YEL"$N�ͺ�һ����һ�����е�"+weapon->name()+"����ʯ���ȥ��\n"NOR,me);
   me->improve_skill("spear",me->query_int()/2+20+random(5));
   me->add("sen",-20);
   if(me->query_skill("spear",1)<50)
   message_vision("$N�������㣬�˲���ʯ��ֺ���\n",me);
   else if(me->query_skill("spear",1)<100)
   message_vision("ֻ�����һ����ʯ���ϱ�$N�̳���һ��ǳ�ӡ�\n",me);
   else if(me->query_skill("spear",1)<150)
   message_vision("ֻ�����һ����$N��"+weapon->name()+"��͸ʯ��\n",me);
  
   return 1;
}
