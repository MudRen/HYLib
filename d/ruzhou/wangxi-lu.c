//Room: /d/ruzhou/wangxi-lu.c
// llm /99/07/

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����·�������飬�Դ˳����ݵ������ţ�����̤����ȥ���У�Զ
�������Ĵ�·�ˡ�����������ݳǵ�֪�����ţ���Ȼδ��ʲô���ɣ�
�������Ե���ĺ�ľ��ǽȴ���ֳ�һ�������������µĸо�����ȥ��
���ݳ����ģ�����Ҳû��ʲô���̡�
LONG
	);

	set("exits", ([
      "north" : __DIR__"yamen-damen",
		"west" : __DIR__"ximen",
		"east" : __DIR__"ruzhou",
	]));

        set("objects", ([
        ]));

	set("outdoors", "ruzhou");
	setup();
	replace_program(ROOM);
}



