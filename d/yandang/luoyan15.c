// Room: /d/yandang/luoyan15.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ׯ���ճ����������ĵط�,���пտ���Ҳ,�����Ҷ���������һ
ͷ����,��������,�������е�ʯ����,΢΢�°�,�ǳ��������������γ�
��,����ʮ�ָɾ�,һ����Ⱦ.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"luoyan13",
]));
	set("no_clean_up", 0);
	//set("no_fight", 1);
	//set("no_magic", 1);

	setup();
}
void init()
{
	if(interactive(this_player()))
	{
		remove_call_out("fastleave");
		call_out("fastleave",random(10)+10,this_player());
	}
}

int fastleave(object me)
{
	object leaf;
	if(me)
	if(environment(me) == this_object())
	{
		tell_object(me,"�㿴���Ҷ��Ĵ���,����һ���Ժ�,�͵��ѹ���,����.....\n");
		me->move("/d/yandang/shanxia.c");	
	}
}
