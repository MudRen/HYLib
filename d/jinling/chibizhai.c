
inherit ROOM;

void create()
{
        set("short", "���ˮկ");
        set("long", @LONG
��͢�ĳ��ˮʦפ���ڸ��������֣�һ����ȥ�������鲴����
��С����ս����ˮӪ�ﵶǹ�����������������޴�����ʾ���л���
���ľ������ٽ��ͱ��Ͽ��С���ڡ��������֣���˵�ǳ��֮ս��
��ͳ˧��褵��ֱʡ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
	"west" : __DIR__"chibi",
	"south" : __DIR__"chibibing",
]));
        set("outdoors", "jinling");
 set("outdoors", "jinling"); 
        set("objects", ([
              __DIR__"npc/ye" : 1,
			]) );

        setup();
//        replace_program(ROOM);
}
