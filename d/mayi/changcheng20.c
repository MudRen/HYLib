inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
�����ǳ��ǵ�һ�����ڣ��س����ӳ��ǣ�ÿ����ʮ�ｨ��һ������
����פ�����ӣ�����������İ���ƽ�����йٱ���������Ѳ�ߣ�����ͻ
�ʿ��������Ҳû��ʲô�����ˡ�
LONG
	);
set("outdoors", "mayi");
set("valid_startroom", 1);
set("exits", ([
	        "northeast" : __DIR__"changcheng21",
	        "southwest" : __DIR__"changcheng19",

	]));
set("objects",([

  __DIR__"npc/bing":2,

  __DIR__"npc/wujiang":1,

  ]));
	
       setup();
	replace_program(ROOM);
}
