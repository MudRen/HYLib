//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "����ѩɽ");
	set("long", @LONG
����һƬ��ѩɽ֮�У��˵�ֻ�ǰ�ɽ����ȴ�Ѿ���ѩ��������
��̹��ˡ���ͷ��ȥ�����׵ķ���������У����Ҳ�����ر����䡣
�ɴ����ϵ�ɽ�������������ټ���ֻ���°��ɵ�ɽ��������ľ������
�������޺��е������ˡ��򶫲�Զ��һ������������ڳ�ɽ����֮��
�����һƬ�ȵء�
LONG
        );

	set("exits", ([
		"westdown" : __DIR__"minov50",
//		"eastdown" : __DIR__"shanlu2",
		]));

	set("outdoors","dali");
	set("cost", 5);
	setup();
}
