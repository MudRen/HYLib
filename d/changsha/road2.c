// /d/zhuojun/road2.c
// Room in �ÿ�
// modify by yang

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ���Ȼ�ֽ����´��ң��������ܻ�
�����������������ӵġ����̵ġ����Ŵ󳵵���������������ǳ���
�֡���ʱ����������������߷ɳ۶���������һ·���������ϵ��˸�
�����ž�װ���¼��������еĻ���������ŵ�������������Щϰ��Ľ�
���ˡ���·��������������������֡�
LONG );
	set("exits", ([
//		"north": "/d/yuyang/edao14",
		"west" : __DIR__"road3",
		"east" : __DIR__"road1",
//		"south" : "/d/xucheng/dadao1",
	]));
       set("objects",([
                __DIR__"npc/shang" : 1,
        ]));
	set("outdoors", "zhuojun");
	setup();
	replace_program(ROOM);
}



