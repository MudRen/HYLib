//yangzhou  caifengdian.c
inherit ROOM;

void create()
{
        set("short", "�÷��");
        set("long", @LONG
���߽�һ������˲�ƥ�ĵ���,ԭ����һ�Ҳ÷��.������һ��������
¡������,�����߲����߹��Թ�Ϳ�֪�����������һ������,��Ҫ������
Ȥ�Ļ����������ﶨ�����ѡ��ڹ�̨���и�����(sign)��
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "west" : __DIR__"nanjie1",

]));
        set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "���������·�, �۸����(��ȡ) 

",
]));
        set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/clother" : 1,
//__DIR__"npc/clother1" : 1,
]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
