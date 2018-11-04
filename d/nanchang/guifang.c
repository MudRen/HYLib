
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short","�뷿�ſ�");
  set ("long", @LONG
�����������Ů���Ĺ뷿���ſڣ�������ż����ʻ�����������
��Ů����Ҫ�����ˣ�����������úõĴ�硣
LONG);

  set("exits", ([ 

  "north":__DIR__"tingyuan",
  "enter":__DIR__"room",
     ]));

set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object me,string dir)
{
	if(me->query_temp("defence_girl")&&dir=="enter")
		return notify_fail("�㻹�������Ᵽ����С��ɣ�\n");
	if(me->query("gender")=="����"&&dir=="enter")
		return notify_fail("���˻��ǲ�Ҫ��ȥ�ˣ�\n");
	return ::valid_leave(me,dir);
}
		
void init()
{
	object *ob,where;int i;
	where=find_object(__DIR__"guifang");
	ob=all_inventory(where);
	for(i=0;i<sizeof(ob);i++)
	{
		if(ob[i]->query_temp("defence_girl")&&!ob[i]->query_temp("defence_flag"))
		{	ob[i]->set_temp("defence_flag",1);
		call_out("bing_come",30+random(10),ob[i]);}
	}
	return;
}

void bing_come(object me)
{
	object killer;
	if(!objectp(me)||!me->query_temp("defence_girl"))
	{ remove_call_out("bing_come");return;}
	killer=new(__DIR__"npc/guanbing");
	killer->set("combat_exp",me->query("combat_exp"));
	killer->kill_ob(me);
	killer->set_name("�ٱ�",({"bing"}));
	killer->delete("family");
	killer->delete("nickname");
	killer->delete("title");
	killer->delete("shili");
	killer->move(environment(me));
	tell_object(environment(me),"һ���ٱ����˹�����\n");
	message_vision("$N��Ҫ���ţ���$n��ס�ˣ�\n",killer,me);
	message_vision("$N��$n�е������Ƿ��������£����ǻ�ˣ�\n",killer,me);
	killer->kill_ob(me);
    remove_call_out("bing_come");return;
}
