// trees2.c
// ������2
inherit ROOM;
void create()
{
	set("short","����");
	set("long",@long
����������ö��ָ��д󣬴ִ����֦��������ཻ����һ����ס��
���⣬������ï�ܵ��Ӳݣ���������಻֪����Ұ����ɢ��������ܺ���
�������������Ϻ��Ӳ�����������ڷ���˻˻����������������ԼԼ�غ�
���м������ݡ�
long);
	set("exits",([
//	    "north" : __DIR__"kongdi",
          "northeast" : __DIR__"treee1",
          "northwest" : __DIR__"treew1",
          "south" : __DIR__"trees1",
]));
set("objects",([
__DIR__"npc/dushe" : 2,
]));
	set("outdoors", "������");
       set("canfindsnake",1);
        setup();
	replace_program(ROOM);
}
	    	
