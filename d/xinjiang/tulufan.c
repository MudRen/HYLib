 inherit ROOM;
void create()
{
        set("short", "��³��");
        set("long", @LONG
������в�������仯�޳������紩�ޣ��紩ɴ�����Ż�¯��
���ϣ�ָ�ľ��������ب����³������в������ǳ��ٺ�ɫɫ��
����ɽ����С˵�����μǡ�������д������չ�����ɽ��������
�����Ĺ��£��ͷ������Ƕ���
LONG
        );
        set("exits", ([ 
  "westup" : __DIR__"sichou3",
  "southwest" : __DIR__"aiding",
  "eastup" : __DIR__"emin",
]));
        set("objects", ([
        __DIR__"npc/girl" : 2,
                        ]) );
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
        set("coor/x",-1060);
        set("coor/y",2030);
        set("coor/z",-10);
        setup();
        replace_program(ROOM);
}     
