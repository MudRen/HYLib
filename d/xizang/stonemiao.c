 // work.c
//#include "/feature/damage.c" 
inherit ROOM; 
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
����������Ϊ�վ�ʧ�޶����������ڵ�װ�μ�ª������һ�Ź����ʯ��������
��ʯ��֮�⣬����ʲô��û�С����а�����һ������ʯ��ʯ��ı�����Ȼ������
����������ֲ�ɫ��������Ψһֵ����ο���ǣ���������ǰ��ʯ���ϣ����ʢ��
ʯ������ʥĸѩ���ɽ�Ŷ��𣬵����Ըߣ���������Ŷ����Ǹо���һ�������ʯ
����վ��������Ů��̸����Լ���������ᵽʲô�����ӡ��������ӡ������ľ֡���

LONG
        ); 
    set("exits", ([ /* sizeof() == 1 */
                "northdown" : __DIR__"stoneroad",
        ])); 
        set("objects", ([
                __DIR__"npc/master4" : 1,       
                __DIR__"npc/master3" : 1,       
                __DIR__"npc/master2" : 1,       
                __DIR__"npc/master1" : 1,       
        ]));
    set("indoors", "guanwai"); 
    set("coor/x",-1240);
        set("coor/y",-50);
        set("coor/z",10);
        setup();
}      
