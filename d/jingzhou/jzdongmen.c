// Room: /d/jingzhou/jzdongmen
// netkill /98/8/14/


inherit ROOM;

void create()
{
        set("short", "���ݶ���" );
        set("long", @LONG
�������ţ������������Ǿ���Ҫ�أ���˳�ǽ��ʵ�ޱȣ���¥�߸�
�������������˺ܶ࣬����Ҳ�Ǵ���ؽ�����ԭ�ıؾ�֮·�����Ը�ɫ
�˵Ȼ��ӣ��㻹��С��һ�㡣��ȥ��ͨ�����ݵ�·��
LONG
        );
        set("outdoors", "city");
        set("objects", ([
            __DIR__"npc/bing" : 2,
        ]));

        set("exits", ([
  "east" : __DIR__"guandao3",
  "west" : __DIR__"dongdajie2",
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}

