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
	        "westdown" : __DIR__"changcheng22",

	]));
set("objects",([

  __DIR__"npc/bing":2,

  __DIR__"npc/wujiang":1,

  ]));
	
       setup();
	replace_program(ROOM);
}
