// story:laojun

#include <ansi.h>

string give_gift();

private mixed *story = ({
        "ŷ���ˣ��常�������....",
        "ŷ����˵����ʲô�£�",
        "ŷ���ˣ���������Ǹ��²�����........",
        "ŷ����̾��һ��������û�ã���60�껹���С�",
        "ŷ���ˣ�.........",
        "ŷ���棺" RED "�������Ǽ��洫����ҩ������" NOR,
        "ŷ���ˣ�������....", 
        "ŷ���棺" HIG "ͻȻ���һ�������˷�..." NOR,
        "ŷ���棺" RED "�ѵ�ҩ������ɽ" NOR,
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
        STORY_D->give_gift("/clone/gift/neili", 1,
                           HIM "\n��ž����һ��һö�ɵ���������ǰ��\n\n" NOR);
        return HIM "��˵����ɽ������һö�ɵ���\n" NOR;
}
