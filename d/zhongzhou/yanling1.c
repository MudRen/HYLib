inherit ROOM;
void create()
{
  	set ("short", "������·");
  	set ("long", @LONG
����������궫·�������ݵ�һ���Ͻ֡����ߵķ��ݿ���
ȥ�Ѿ��ܳ¾��ˡ��ֵ�����������ģ�ż��һ������·������
��ǰ�ߣ����������Ŀ������ݵ�����¥�ˡ�·�����м��ӻ���
������ƫƧ�ĵط����������ⲻ��̫�á�
LONG);

	set("outdoors", "zhongzhou");

  	set("exits", ([  
    		"west" : __DIR__"yanling2",
    		"north" : __DIR__"zahuopu",
    		"east"  : __DIR__"yanling",
	]));
        set("objects",([
                __DIR__"npc/fushang":1,
                __DIR__"npc/poorman":1,
        ]));
       
        set("coor/x", -250);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
