//Room: /d/city/shuyuan2.c

string look_shelf();


inherit ROOM;

void create()
{
	set("short", "��ѩ��");
	set("long", @LONG
�����������������Ͼʱϲ�������ĵط������ﴰ��������һ����
Ⱦ�����ϵ����(shelf) ���������е������ǵ���ѡ����¼�������е�
�����������������������ֺ����ŵĴ�˵����Ȼ��Щ�����Ѿ���ң
Զ��ȴ����ĥ��������Ķ�(read)����Щ���ϵĹ��¡�¥�������Ժ��
�ղ��н�ӹ��ʦ����Ҫ��Ʒ��
LONG);
	set("item_desc", ([
		"shelf" : (: look_shelf :),
	]));
	set("no_fight", "1");
	set("no_beg", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("no_clean_up", 0);

	set("exits", ([
		"down" : __DIR__"shuyuan1",
		"up"   : __DIR__"shuyuan3",
	]));
	set("objects", ([
		//__DIR__"obj/wizboard" : 1,
	]));
	set("coor/x", 20);
	set("coor/y", 32);
	set("coor/z", 20);
	setup();
//	"/clone/board/shuyuan_b"->foo();
}

