
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ׯ�ڵ�");
        set("long", @LONG
������һƬׯ�ڵء���ز��󣬵���ׯ�ڿ��������ĺܺá��м���
С�����Ա���ˣ��Զ���м���ũ�����������һ����紵������Ұ��
��Ϣ���������Ŀ�����������Ա߷��ż������ˣ���֪���߼��»���ô
����
LONG
);
        set("exits",([
	"southup" : __DIR__"xiaolu2",
	
        ]));
set("outdoors","gaoli");
        setup();
//        replace_program(ROOM);
}

void init()
{
   add_action("do_ci","ti");
}

int do_ci(string arg)
{
   object me;
   me=this_player();
   if(!arg||arg!="����")
   return notify_fail("��Ҫ��ʲô��\n");
  
   if(me->query("sen")<20)
   return notify_fail("�㾫��̫���ˣ�\n");
   if(me->query_skill("leg",1)>=101)
   return notify_fail("һ��ũ�����˹������٣���Ҫ�����ҵĲ��ˣ�\n");
   if(me->is_busy())
   return notify_fail("����æ���أ�\n");
   
   message_vision(YEL"$Nһת��Ȼ��̧�ȳ�������ȥ��\n"NOR,me);
   me->improve_skill("leg",me->query_int()/2+20+random(5));
   me->add("sen",-20);
   if(me->query_skill("leg",1)<50)
   message_vision("$N���̲��ȣ���Щ������\n",me);
   else if(me->query_skill("leg",1)<100)
   message_vision("$N����վ�ã�΢΢һЦ��\n",me);
   else if(me->query_skill("leg",1)<150)
   message_vision("$N������һ��ת����������վ�ã�\n",me);
  
   return 1;
}
