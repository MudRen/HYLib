// treen2.c
// ���ֱ�2
inherit ROOM;
void create()
{
	set("short","����");
	set("long",@long
����������ö��ָ��д󣬴ִ����֦��������ཻ����һ����ס����
�⣬������ï�ܵ��Ӳݣ���������಻֪����Ұ����ɢ����������ܺ��ŵ���
���������Ϻ��Ӳ�����������ڷ���˻˻���������ϱ�����ԼԼ�غ����м���
���ݡ�
long);
	set("exits",([
	    "north" : __DIR__"treen1",
          "southeast" : __DIR__"treee1",
          "southwest" : __DIR__"treew1",
          "eastup" : __DIR__"sanpo7",
]));
set("objects",([
__DIR__"npc/dushe" : 2,
]));
	set("outdoors", "������");
       set("canfindsnake",1);
        setup();
}
	    	
