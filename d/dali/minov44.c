//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
�����������ļ�����ݣ���Ϊ������������һ����̨��̨�ϰ�
����һ��������λ����������������֮������λ���ǽ�Ϲ��д����
Ƥ���ϻ����λ��ƣ����Ǹ����ͼ�ڡ�һλ�ϼ�˾�������ڼ�̨ǰ��
����ȫ��ļ�˾���
LONG
        );

	set("exits", ([
		"out" : __DIR__"minov43",
		]));

	set("objects", ([
		__DIR__"npc/wyjisi.c" : 1,
		]));

	set("cost", 2);
	setup();
}
