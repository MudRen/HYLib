// story:laojun

#include <ansi.h>

string give_gift();

private mixed *story = ({
        "�������ƣ���ͤ�������������",
        "����ͤЦ������������������㵽��һ���ɵ�������ʹ�˱�ĸ�����",
        "�������ƴ�ϲ�����ã������һ�š�",
        "����ͤ�ͳ�һ��«�����������",
        "�������ƣ�" HIY "��ѽ��" NOR,
        "����ͤ�����ã���ô�����˺�ľ���ˣ���������ȥ���ҡ�",
        "�������ƣ��������ˣ����Ѿ�������......��",
        (: give_gift :)
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

string give_gift()
{
        STORY_D->give_gift("/clone/gift/perwan", 1,
                           HIM "\n��ž����һ��һö�ɵ���������ǰ��\n\n" NOR);
        return HIM "��˵�������������һö�ɵ���\n" NOR;
}
