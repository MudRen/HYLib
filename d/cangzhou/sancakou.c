// By River@SJ 2001/9  

inherit ROOM;

void create()
{
        set("short", "����·");
        set("long", @LONG
������һ���������������·�ϡ��������������������ӵ����̣����Ŵ�
��������Ͼ��Ͽ��������������������ǳ����֡�����������ͨ�����ǵı�
��֮·�������߾��ǲ����ˣ�������һ����·��ͨ���ľ�̿��Ƶ�ƽ���ݡ�
LONG
        );
        set("outdoors", "����");
        set("exits", ([ 
		"west" : "/d/heimuya/road3",
		"southeast" : __DIR__"wroad4",
//		"northeast" : "",
        ]));
	set("no_clean_up", 0);

	setup();
}
