// Room: /d/yandang/shandong5
#include <ansi.h>
inherit ROOM;

void create()
{
  set ("short", "���˶�");
  set ("long", @LONG
����һ������,��ȴʮ�ֹ���,Ҳ��֪���ߴӺδ���,������������
һ��˵�������İ�ɫ��ʯ���,���Ǽ�Ӳ.�ڶ���,��Ȼ���ż����'����
������,������ע��',��������ǹ����.����������һ��ʯ��¯(lu).
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shandong4",
  "northup" : __DIR__"shandong6",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "lu" : "һ���޴����¯,���ڹ�����������ǩ����������(born)һ�¿���.
Ҳ�������漣Ү.
",
]));
  setup();
}
void init()
{
	add_action("do_born", "born");
}
int do_born(string arg)
{
		object me,ob;
		me=this_player();
             ob=present("qian",me);
             if (!ob) return notify_fail("������û����ǩ!\n");

	    if( (arg!="qian")&&(arg!="��ǩ") ) return notify_fail("��Ҫ��ʲô?\n");
	    	message_vision("$N����ǩͶ����¯��,һ����ɫ����ӿ����,��ǩ��û�ˡ�\n", this_player());
		switch( random(3) ) 
		{
			case 0:
                    message_vision(HIC"һ���ּ��ڻ������Լ����:������Ϭ,��������.\n"NOR,me);
                    tell_object(me,"������һ��,��̨����,��ľ���������!\n");
                    me->set("combat_exp",(me->query("combat_exp"))+150);				
                    break;
			case 1:
                    message_vision(HIC"һ���ּ��ڻ������Լ����:ǰ�����ǽ�����,��������������.\n"NOR,me);
                    tell_object(me,"������������������,������һƬƽ��!\n");
		       break;
			case 2:
                    message_vision(HIC"һ���ּ��ڻ������Լ����:ǰ;����,��ͷ�ǰ�!\n"NOR,me);
                    tell_object(me,"������һ����ã,���񲻶�,��ľ����½���!\n");
                    me->set("combat_exp",(me->query("combat_exp"))-150);				
				break;
		}
          destruct(ob);
		return 1;
}
