inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�˼��ǹ����ǵ����ţ���Ϊ�������򡣳�ǽ��ʯ������ݳɣ��߶�
���壬�����ɡ��������������������ľ�ʿ�ɴ����۾��۲���������
�������ˣ�ż�����ʼ����μ����ɷ��ӡ�
LONG );

	set("exits", ([
                          "east"      : __DIR__"xidajie",
                         "west"      : __DIR__"tulu1",
                         "north"      : __DIR__"guanlu1",
		
	]));
set("objects",([
           __DIR__"npc/bing":2,
           __DIR__"npc/wujiang":1,
           ]));

 	set("outdoors", "guizhou");
	setup();
	replace_program(ROOM);
}



