
inherit ROOM;

void create()
{
        set("short", "̫��ˮկ");
        set("long", @LONG
̫��ˮկ�ǳ�͢����ˮʦ----̫��ˮʦ��פ��֮�أ����ٳ�
ɽ�뵺������ˮӪ������С����ս����װ���������ͻ��ڣ���ǹ��
����������չ��ɷ�����硣������̨������̫������Ӱ��㣬����
����������ɽ����꾲����Զ����ɽ�翥���ۣ���һ��ɽ����
�����ɺ��⿪��Ұ�ķ�⡣
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
	"west" : __DIR__"taihu",
	"south" : __DIR__"taihubing",
]));
        set("outdoors", "jinling");
        set("objects", ([
              __DIR__"npc/xiao" : 1,
			]) );

        setup();
//        replace_program(ROOM);
}
