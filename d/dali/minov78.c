//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
����һƬʪ������֣�����ˮ��������·���У�ʮ���ɸߵľ޴�
�����̸���ڣ����ɴֵü����˺ϱ�ҲΧ��ס����������֦�´�����
ˮ�з�������������Ϊ����ľ��¡�������Ȼ�������ޣ�ȴ�Ƿ��ݾ�
�ӵ���������������̨��������Խ�ڴ�������¶�ĸ�֦�ϣ��ö���
���Է���
LONG
        );

	set("exits", ([
		"west" : __DIR__"minov76",
		]));

	set("objects", ([
		__DIR__"npc/tylieren" : 1,
	]));

	set("outdoors","dali");
	set("cost", 5);
	setup();
}
