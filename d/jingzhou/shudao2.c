// Room: /d/chengdu/shudao2
// netkill /98/8/16/


inherit ROOM;

void create()
{
        set("short", "��ʯ·" );
        set("long", @LONG
һ����ʯ�̳ɵ�·��ƽ̹������·�����档����������������
���˶�������ȥ�˳�����ЪЪ�ţ�һЩС��Ҳ�˻����������Ժȵ�
���������������Ͽ�ȥ����Լ���Կ������ڵĳ�����
LONG
        );
        set("exits", ([
  "east" :    __DIR__"shudao1",
  "southwest" : __DIR__"shudao3",
   ]));

        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        setup();
        replace_program(ROOM);
}

