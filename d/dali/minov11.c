//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "��٤��");
	set("long", @LONG
�����ǵ�صĶ��ϣ���ôЩ������٤����۾ӵĵط���ôЩ����
�����ġ�����ϲ��ƽԭ��ˮ������ˮ��ƽԭ���ӣ���Ϊ���顱������
���������֣���ȱ��ס���٤��һ�����䣬��٤���Ǹ��൱�����
�ӣ�����������������θ���
LONG
        );

	set("exits", ([
		"northwest" : __DIR__"dianchi",
		"southwest" : __DIR__"minov12",
		"east" : __DIR__"minov13",
		]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
