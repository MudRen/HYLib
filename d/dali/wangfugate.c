//Room: /d/dali/wangfugate.c
//Date: June. 29 1998 by Java
//����(lywin)�޶���2000��8��13��

inherit ROOM;
void create()
{
	set("short","��������");
	set("long",@LONG
����վ��һ�������ĸ���ǰ����ǰ����ֻ�����ʯʨ�ӣ����ϸ�
��һ����ң����顸�����������ĸ����֡��ſ�վ����������������
���£���ִ�ֵ�������������
LONG);
	set("objects", ([
	   CLASS_D("dali")+"/zhuwanli": 1,
	   __DIR__"npc/weishi2": 1,
	   __DIR__"npc/weishi1": 2,
	   "/d/biwu/champion_dl":1,
	   "quest/menpai/dali/shi":1,
	]));
	set("valid_startroom", 1);
        set("no_sleep_room",1);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "enter"  : __DIR__"wfdating",
	    "south"  : __DIR__"wangfulu",
//	    "west"  : "quest/menpai/dali/room",
	]));
	setup();
	"/clone/board/dali_b"->foo();
}
