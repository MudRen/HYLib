 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�����Ǽ��ϰ����ŷ�ɥ���ĵ��Σ���˵����ͨǿ��С����������������
���죬��������Σ�Ҳֻ�е������������λ������ظߵ�ˮ������̹ǣ�����
�ϳ��그�˵�Ѫˮ����й���Ѿ�������������а������գ�ֻ�ж���һ˿˿΢
��ʹ�������������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northup" : __DIR__"andao2",
]));
        set("objects", ([
        __DIR__"npc/laoqi" : 1,
                        ]) ); 
    set("coor/x",90);
    set("coor/y",1870);
    set("coor/z",-20);
        setup();
        replace_program(ROOM);
} 
