inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�˼��ǹ����ǵı��ţ���Ϊ�������򡣳�ǽ��ʯ������ݳɣ��߶�
���壬�����ɡ��������������������ľ�ʿ�ɴ����۾��۲���������
�������ˣ�ż�����ʼ����μ����ɷ��ӡ�
LONG );

	set("exits", ([
                          "north"      : __DIR__"dadao1",
                         "south"      : __DIR__"beishi",
	                  "northwest":__DIR__"qingshilu4",	
	]));
          set("objects",([
           __DIR__"npc/bing":2,
           __DIR__"npc/wujiang":1,
           ]));

 	set("outdoors", "guizhou");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



