// Room: xiangfang.c
// By River 98/12
inherit ROOM;
void create()
{
        set("short", "�᷿");
        set("long", @LONG
���������᷿�����ܲ���һ����֪��С��Ĺ뷿��ʯ��ʯ�ʣ�����ɽҰ��
Ϣ�������ҹ���Щ�黭��һ����֪������û��ʲô�����ġ�����ʢ����һЩҰ
ɽ�軨����Զ����ɽʯ������������һ��ɽ���
LONG
        );
        set("exits", ([            
            "west" : __DIR__"keting",
        ]));

        set("objects", ([
              __DIR__"npc/gan_baobao" : 1,
        ]));
        
        setup();
        replace_program(ROOM);
}
