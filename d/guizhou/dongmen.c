inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�˼��ǹ����ǵĶ��ţ���Ϊ�������򡣳�ǽ��ʯ������ݳɣ��߶�
���壬�����ɡ��������������������ľ�ʿ�ɴ����۾��۲���������
�������ˣ�ż�����ʼ����μ����ɷ��ӡ�
LONG );

	set("exits", ([
                    "east"      : __DIR__"dadao2",
                         "west"      : __DIR__"dongdajie",
		
	]));
set("objects",([
           __DIR__"npc/bing":2,
           __DIR__"npc/wujiang":1,
           ]));

 	set("outdoors", "guizhou");
	setup();
	replace_program(ROOM);
}



