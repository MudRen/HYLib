
inherit ROOM;

void create()
{
        set("short", "��ڱ�����");
        set("long", @LONG
����һ���Ӵ�ı��������ǹ���������ר�������������װ��
�ĵط��������ɼ���������¯�����й��˶���æµ�ع����ţ��е�
�������еĶ��죬�е�װ�䣬��һ���Ȼ���ľ��󡣲�Զ������
һ�Ÿ��ƺõĳ�Ʒ��
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
	"north" : __DIR__"chibizhai",
]));
        set("outdoors", "jinling");
        set("objects", 
        ([ //sizeof() == 1
              "/d/hainan/npc/man1" : 2,
        ]));
	set("no_fight",1);
	set("no_study",1);
	set("no_magic",1);
	set("hell",1);
	set("NONPC",1);

        setup();
//        replace_program(ROOM);
}

