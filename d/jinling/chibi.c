
inherit ROOM;

void create()
{
        set("short", "���ɽ");
        set("long", @LONG
��ڹ���ʯͷ�أ������й�ս�������ۺۼ�������ɽ����ΰ��
бب���ɣ�ͻ�볤�������˷ɽ����ߴ����࣬���ư��硣����ɽ��
�İݷ�̨����˵��������趫��֮������������ǳ��֮ս������
�Ƶ���ͳ����֮�ء�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
	"east" : __DIR__"chibizhai",
	"southwest" : __DIR__"jiangdao6",
]));
        set("outdoors", "jinling");

        setup();
        replace_program(ROOM);
}
