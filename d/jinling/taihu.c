
inherit ROOM;

void create()
{
        set("short", "̫��");
        set("long", @LONG
̫���ܳ��������Ϊ������Ǯ�������εĺ����ں����ֳ���
�������Ϊ����ˮ�����ġ������д�С������ʮ�˸����Զ�ͥ��
ɽ����ɽΪ��󡣺����̲����죬���측�����������������԰
�ֵ�׺������һ��ɽ����ɽ�������к�����Ȼͼ����
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
	"east" : __DIR__"taihuzhai",
	"northwest" : __DIR__"jiangdao4",
]));
        set("outdoors", "jinling");

        setup();
        replace_program(ROOM);
}
