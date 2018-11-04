//Cracked by Kafei
// Room: /d/dali/garden1.c

inherit ROOM;

void create()
{
	set("short", "�軨԰���");
	set("long", @LONG
��һ����ɫ��ʯǽ���棬�������Կ���һ���ŵĴ�������
ʯ��ǰվ��һ���ϻ����������ŵ����Ư���ĵ����軨��ζ��
���в���һ��������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : "/d/dali/wfdating",
  "enter" : __DIR__"garden2.c",
]));
	set("no_clean_up", 0);
	set("cost", 1);
	set("objects", ([
		__DIR__"npc/chahua" : random(2),
		]));

	setup();
//	replace_program(ROOM);
}
void init()
{
	add_action("do_get","get");
}

int do_get(string arg)
{
	object me, ob, weapon;
	me=this_player();

	if (arg=="cha" || arg=="chahua" || arg=="all" || arg=="cha hua") {
		if (!objectp(ob=present("cha", environment(me)))) {
			tell_object(me, "����ûʲô��Ʒ�ֵĲ軨ֵ�����ߡ�\n");
			return 1;
		}
		if (!objectp(weapon=me->query_temp("weapon"))
			|| weapon->query("id")!="huachu") {
			tell_object(me, "��û�г��ֵĹ�������ֲ����軨��\n");
			return 1;
		}
		if (random(2)==1) {
			message_vision("$NС��������û�������軨�ĸ���������軨����������\n", me);
			ob->move(me);
		}
		else {
			message_vision("$N����ææ���ڲ軨��һ��С�İѸ��ڶ��ˣ��úõ�һ��軨�����ˡ�\n", me);
			destruct(ob);
		}
		return 1;
	}
	return 0;
}
