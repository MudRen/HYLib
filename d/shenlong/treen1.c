// treen1.c
// ���ֱ�1
inherit ROOM;
void create()
{
	set("short","����");
	set("long",@long
����������ö��ָ��д󣬴ִ����֦��������ཻ����һ����ס����
�⣬������ï�ܵ��Ӳݣ���������಻֪����Ұ����ɢ����������ܺ��ŵ���
���������Ϻ��Ӳ�����������ڷ���˻˻��������
long);
	set("exits",([
	    "southeast" : __DIR__"treee1",
          "southwest" : __DIR__"treew1",
          "south" : __DIR__"treen2", 
          "north" : __DIR__"haitan",
]));
set("objects",([
__DIR__"npc/dushe" : 2,
]));
	set("outdoors", "������");
       set("canfindsnake",1);
        setup();
	replace_program(ROOM);
}
	    	
