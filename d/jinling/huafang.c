//jinling  huafang.c
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�������ػ����ϵ�һ������.�������������Ƿ�,������Ҫ��������Ĺ�
���Ƕ�����˵��ɫ��˫��������������������̼���ʿ�޲�������������
һ�÷��ʡ���û�е���ݵ����ǲ������ױ������ǽӼ��ġ�
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "south" : __DIR__"huaihe",


]));
set("objects", ([
              __DIR__"npc/yutt" : 1,
              __DIR__"npc/xuezi" : 1,
			]) );
    // set("outdoors", "jinling");

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}